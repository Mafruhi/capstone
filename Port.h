
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Multiple Scenes");
    glutPositionWindow(30, 50);

    glutDisplayFunc(GraphicsScene::display);
    glutKeyboardFunc(GraphicsScene::keyboard);

    glutMainLoop();
    return 0;
}
