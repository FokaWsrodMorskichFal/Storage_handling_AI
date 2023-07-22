package storagehandlingai;

import storagehandlingai.warehouse.Warehouse;

public class App {

    public static void main(String[] args) throws InterruptedException {
        Warehouse warehouse = new Warehouse(500, 500);
        Scene scene = new Scene(warehouse);
        while (true) {
            scene.redraw();
            Thread.sleep(50);
        }
    }
}
