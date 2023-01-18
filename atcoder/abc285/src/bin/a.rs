fn main() {
    proconio::input! { a: u8, b: u8 }
    println!("{}", if a == b >> 1 { "Yes" } else { "No" })
}
