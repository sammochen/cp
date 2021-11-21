namespace Timer {
chrono::high_resolution_clock::time_point prev;
void start() {
    prev = chrono::high_resolution_clock::now();
}
void stamp() {
    auto cur = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms = cur - prev;
    string time = to_string(ms.count()) + "ms";
    cout << "time: " << time << endl;
}
};  // namespace Timer