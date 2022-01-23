#include<Windows.h>
#include<osg/MatrixTransform>
#include<osgDB/ReadFile>
#include<osgViewer/Viewer>

int main (int argc, char* argv[]) {

    (void)argc; (void)argv;

    osg::ref_ptr<osg::Node> nathan = osgDB::readNodeFile("nathan.osg");
    osg::ref_ptr<osg::Node> cow = osgDB::readNodeFile("cow.osg");
    osg::ref_ptr<osg::Node> robot = osgDB::readNodeFile("robot.osg");

    osg::ref_ptr<osg::MatrixTransform> transform1 = new osg::MatrixTransform;
    transform1->setMatrix(osg::Matrix::translate(-5.0, 0.0, 0.0));
    transform1->addChild(nathan.get());

    osg::ref_ptr<osg::MatrixTransform> transform2 = new osg::MatrixTransform;
    transform2->setMatrix(osg::Matrix::translate(0.0, 0.0, 0.0));
    transform2->setMatrix(osg::Matrix::rotate(osg::inDegrees(-90.0f), 0.0f, 0.0f, 1.0f));
    transform2->addChild(cow.get());

    osg::ref_ptr<osg::MatrixTransform> transform3 = new osg::MatrixTransform;
    transform3->setMatrix(osg::Matrix::translate(6.0, 0.0, 0.0));
    transform3->addChild(robot.get());

    osg::ref_ptr<osg::Group> root = new osg::Group;
    root->addChild(transform1.get());
    root->addChild(transform2.get());
    root->addChild(transform3.get());

    osgViewer::Viewer viewer;
    viewer.setSceneData(root.get());
    return viewer.run();
}
