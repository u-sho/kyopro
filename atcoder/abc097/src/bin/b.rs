fn main() {
    proconio::input! { x: u16 }
    if x == 1 {
        println!("1");
        return;
    }

    let mut b: u16 = 1;
    let mut ans: u16 = 1;
    while b * b <= x {
        b += 1;
        let mut bp: u16 = b * b;
        while bp <= x {
            ans = std::cmp::max(ans, bp);
            bp *= b;
        }
    }

    println!("{}", ans);
}
