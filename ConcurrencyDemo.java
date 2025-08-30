public class ConcurrencyDemo {
    public static void main(String[] args) {
        Thread upThread = new Thread(() -> {
            for (int i = 0; i <= 20; i++) {
                System.out.println("Counting Up: " + i);
            }
        });

        Thread downThread = new Thread(() -> {
            for (int i = 20; i >= 0; i--) {
                System.out.println("Counting Down: " + i);
            }
        });

        upThread.start();
        try {
            upThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        downThread.start();
        try {
            downThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Both threads have finished.");
    }
}
