
int main() {
    Postscript p("test.ps");
    p.line(50,400, 100,400);
    int r = 255, g = 0, b = 0;

    p.setStrokeColor(r, g, b);
    p.setFillColor(200, 250, 0);
    p.drawRect(0, 0, 100, 100);
    p.fillRect(130, 0, 100, 100);
    p.setFillColor(150, 250, 0);
    //p.setStrokeColor(r, g, b);
    p.drawTriangle(120, 250, 180, 200, 240, 250);
    p.fillTriangle(270, 250, 330, 200, 390, 250);
    p.drawCircle(300, 60, 60);
    p.fillCircle(450, 60, 60);
    p.text(150, 600, "This is the group project of Haiping Zhu and Shuo Lu");
    p.grid(200, 50, 400, 300, 50, 500);
}



