import java.util.Comparator;
import java.util.Random;
import java.util.TreeSet;

public class Ratkaisu {
    public static void main(String[] args) {
        IO io = new IO();

        long n = io.nextInt();
        long k = io.nextInt();
        long t = 0;

        long a,b;

        TreeSet<Asunto> asunnot = new TreeSet<>();
        TreeSet<Hakija> hakijat = new TreeSet<>();
        TreeSet<Asunto> koot = new TreeSet<>();
        for (long i = 0; i < n; i++) {
            a = io.nextInt();
            b = io.nextInt();
            hakijat.add(new Hakija(a, b));
        }
        for (long i = 0; i < k; i++) {
            a = io.nextInt();
            b = io.nextInt();
            asunnot.add(new Asunto(a, b));
        }
        for (Hakija h: hakijat) {
            while (asunnot.size() > 0 && asunnot.first().hinta <= h.hinta ) {
                Asunto ab = asunnot.pollFirst();
                koot.add(new Asunto(ab.koko, ab.hinta));
            }
            Asunto ko = koot.ceiling(new Asunto(h.koko, 0));
            if (ko != null) {
                koot.remove(ko);
                t++;
            }
        }
        io.println(t);
        io.close();
    }
}

class Hakija implements Comparable<Hakija> {

    long koko;
    long hinta;
    int id;

    public Hakija(long h, long k) {
        koko = k;
        hinta = h;
        Random r = new Random();
        id = r.nextInt();
    }


    @Override
    public int compareTo(Hakija o) {
        if (hinta == o.hinta && koko == o.koko) {
            if (id == o.id) {
                return 0;
            }
            return -1;
        } else if (hinta == o.hinta) {
            return (int)(koko - o.koko);
        }
        return (int)(hinta - o.hinta);
    }

    @Override
    public boolean equals(Object o) {
        Hakija h = (Hakija)o;
        return h.id == id;
    }
}

class Asunto implements Comparable<Asunto> {

    long hinta;
    long koko;
    int id;

    public Asunto(long h, long k) {
        hinta = h;
        koko = k;
        Random r = new Random();
        id = r.nextInt();
    }

    @Override
    public int compareTo(Asunto o) {
        if (hinta == o.hinta && koko == o.koko) {
            if (id == o.id) {
                return 0;
            }
            return -1;
        } else if (hinta == o.hinta) {
            return (int)(koko - o.koko);
        }
        return (int)(hinta - o.hinta);
    }

    @Override
    public boolean equals(Object o) {
        Asunto ot = (Asunto)o;
        return ot.id == id;
    }
}