int arr[N];
int X[1<<(N/2)], Y[1<<(N/2)];
int size_X, size_Y;
void meet_in_the_middle(int X[], int n, int c) {
    for (int i = 0; i < (1 << n); i++) {
        int s = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j))
                s += arr[j + c];
        }
        X[i] = s;
    }
}
