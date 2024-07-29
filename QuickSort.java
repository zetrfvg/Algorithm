public void sort(IndexedSortable s, int p, int r, Progressable rep) {
    if (null != rep) {
      rep.progress();
    }
    while (true) {
    if (r-p < 13) {
      for (int i = p; i < r; ++i) {
        for (int j = i; j > p; --j) {
          if (s.compare(j-1, j) > 0) {
            s.swap(j, j-1);
          }
        }
      }
      return;
    }

    // select, move pivot into first position
    fix(s, (p+r) >>> 1, p);
    fix(s, (p+r) >>> 1, r - 1);
    fix(s, p, r-1);

    // Divide
    int x = p;
    int i = p;
    int j = r;
    while(true) {
      while (++i < r && s.compare(i, x) < 0) { } // move lindex
      while (--j > x && s.compare(x, j) < 0) { } // move rindex
      if (i < j) s.swap(i, j);
      else break;
    }
    // swap pivot into position
    s.swap(x, i - 1);

    // Conquer
    // Recurse on smaller interval first to keep stack shallow
    if (i - p - 1 < r - i) {
      sort(s, p, i - 1, rep);
      sort(s, i, r, rep);
    } else {
      sort(s, i, r, rep);
      sort(s, p, i - 1, rep);
    }
    }
