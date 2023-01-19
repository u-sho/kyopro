fn main() {
    // カンニング https://atcoder.jp/contests/abc097/submissions/27944933
    proconio::input! {
        s: String,
        k: usize
    }

    let mut v = vec![];
    for i in 0..s.len() {
        for j in i..(s.len().min(i + k)) {
            v.push(&s[i..=j]);
        }
    }
    v.sort_unstable();
    v.dedup();
    println!("{}", v[k - 1]);
}
