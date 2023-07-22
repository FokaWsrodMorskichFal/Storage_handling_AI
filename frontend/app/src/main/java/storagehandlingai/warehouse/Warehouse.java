package storagehandlingai.warehouse;

import java.util.List;

import lombok.RequiredArgsConstructor;
import storagehandlingai.display.DisplaySize;
import storagehandlingai.display.Drawable;
import storagehandlingai.display.Line;
import storagehandlingai.display.Shape;

@RequiredArgsConstructor
public class Warehouse implements Drawable {

    private final int width;
    private final int height;

    List<Worker> workers;
    List<Box> boxes;

    @Override
    public List<Shape> toShapes() {
        return List.of(
            new Line(DisplaySize.HALF_WIDTH - width / 2, DisplaySize.HALF_HEIGHT - height / 2, DisplaySize.HALF_WIDTH - width / 2, DisplaySize.HALF_HEIGHT + height / 2),
            new Line(DisplaySize.HALF_WIDTH - width / 2, DisplaySize.HALF_HEIGHT - height / 2, DisplaySize.HALF_WIDTH + width / 2, DisplaySize.HALF_HEIGHT - height / 2),
            new Line(DisplaySize.HALF_WIDTH - width / 2, DisplaySize.HALF_HEIGHT + height / 2, DisplaySize.HALF_WIDTH + width / 2, DisplaySize.HALF_HEIGHT + height / 2),
            new Line(DisplaySize.HALF_WIDTH + width / 2, DisplaySize.HALF_HEIGHT - height / 2, DisplaySize.HALF_WIDTH + width / 2, DisplaySize.HALF_HEIGHT + height / 2)
        );
    }

}
