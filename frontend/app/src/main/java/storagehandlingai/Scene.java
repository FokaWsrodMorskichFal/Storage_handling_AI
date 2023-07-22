package storagehandlingai;

import lombok.RequiredArgsConstructor;
import storagehandlingai.display.Canvas;
import storagehandlingai.warehouse.Warehouse;

@RequiredArgsConstructor
public class Scene {
    
    private final Warehouse warehouse;

    public void redraw() {
        var canvas = Canvas.getInstance();
        canvas.clear();
        warehouse.toShapes().forEach(canvas::show);
    }

}
