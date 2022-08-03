Y;
main() {
    scanf("%d", &Y);
    printf("%d", Y + (6 - Y % 4) % 4);
}