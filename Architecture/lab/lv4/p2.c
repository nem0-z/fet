const char* str = "abCdEfgzh ?";
char res[40];

int main(int argc, char* argv[]) {
  const char* s = str;
  int i = 0;
  while (*s != '\0') {
    if (*s > 96) {
      if (*s < 123) {
        res[i] = *s - 32;
      } else {
        res[i] = *s;
      }
    } else {
      res[i] = *s;
    }
    ++s;
    ++i;
  }
  return 0;
}
