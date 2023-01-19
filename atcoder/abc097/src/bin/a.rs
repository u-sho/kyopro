use std::cmp::{max, min};

fn distance(a: u8, b: u8) -> u8 {
    max(a, b) - min(a, b)
}
fn main() {
    proconio::input! { a: u8, b: u8, c:u8, d:u8 }
    println!(
        "{}",
        if distance(a, c) <= d {
            "Yes"
        } else if max(distance(a, b), distance(b, c)) <= d {
            "Yes"
        } else {
            "No"
        }
    )
}
