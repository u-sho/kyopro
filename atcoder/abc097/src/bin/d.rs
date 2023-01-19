fn main() {
    proconio::input! {
        n: usize, m: usize,
        p: [usize; n],
        xy: [(usize, usize); m]
    }

    let mut uf = petgraph::unionfind::UnionFind::new(n + 1);
    for (x, y) in xy {
        uf.union(x, y);
    }

    let mut counter = 0usize;
    for i in 0..n {
        if uf.equiv(i + 1, p[i]) {
            counter += 1
        }
    }

    print!("{}", counter)
}
