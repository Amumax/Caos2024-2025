void true_path() {};
void false_path() {};

void bar(int i) {
    if(i) [[unlikely]] {
        true_path();
    } else [[likely]] {
        false_path();
    }
}


int main() {
  bar(10);
}
