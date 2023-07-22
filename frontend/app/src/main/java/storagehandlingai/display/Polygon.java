package storagehandlingai.display;

import java.awt.Graphics2D;
import java.util.Arrays;
import java.util.List;

public class Polygon implements Shape {

    private final Color color;
    private final int[] xPoints;
    private final int[] yPoints;
    private final int nPoints;
    private final int xPos;
    private final int yPos;
    private final int width;
    private final int height;

    public Polygon(List<Point> points) {
        this(points, Color.BLACK);
    }

    public Polygon(Point... points) {
        this(Arrays.asList(points));
    }

    public Polygon(Color color, Point... points) {
        this(Arrays.asList(points), color);
    }

    public Polygon(List<Point> points, Color color) {
        nPoints = points.size();
        xPoints = points.stream().mapToInt(Point::x).toArray();
        yPoints = points.stream().mapToInt(Point::y).toArray();
        int xMin = points.stream().mapToInt(Point::x).min().getAsInt();
        int yMin = points.stream().mapToInt(Point::y).min().getAsInt();
        int xMax = points.stream().mapToInt(Point::x).max().getAsInt();
        int yMax = points.stream().mapToInt(Point::y).max().getAsInt();
        xPos = xMin;
        yPos = yMin;
        width = xMax - xMin;
        height = yMax - yMin;
        this.color = color;
    }


    @Override
    public int getX() {
        return xPos;
    }

    @Override
    public int getY() {
        return yPos;
    }

    @Override
    public int getWidth() {
        return width;
    }

    @Override
    public int getHeight() {
        return height;
    }

    @Override
    public void paintShape(Graphics2D g2) {
        if (color != null) {
            g2.setColor(new java.awt.Color((int) color.getRed(), (int) color.getGreen(), (int) color.getBlue()));
            java.awt.Polygon polygon = new java.awt.Polygon(xPoints, yPoints, nPoints);
            g2.fillPolygon(polygon);
            // g2.draw(polygon);
        }
    }
    
}
