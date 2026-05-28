use std::time::{Duration, Instant};

fn fipou(fibs: &mut Vec<i64>) {
    let len = fibs.len();
    let next = unsafe {
        fibs.get_unchecked(len - 1)
            .wrapping_add(*fibs.get_unchecked(len - 2))
    };
    fibs.push(next);
}

fn main() {
    let mut fibs: Vec<i64> = vec![0, 1];
    let start = Instant::now();
    let mut count = 0u64;

    while start.elapsed() < Duration::from_secs(1) {
        fipou(&mut fibs);
        count += 1;
    }

    println!("{}", fibs.last().unwrap());
    println!("Ran {} times in 1 second", count);
}
