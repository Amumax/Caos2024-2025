  # Раздел 1. Линковка и библиотеки. Понятие сисколлов

## 1. Стадии сборки

```bash
# Посмотреть этапы сборки
g++ -v test.cpp

# Получить ассемблерный код
g++ -S test.cpp

# Получить объектный файл  
g++ -c test.cpp

# Дизассемблировать исполняемый файл
objdump -d a.out
```

## 2. Линковка вручную

```bash
# Компилируем в объектный файл
g++ -c test.cpp -o test.o

# Линкуем вручную со стандартной библиотекой
ld -o program test.o -lc -lstdc++ /usr/lib/x86_64-linux-gnu/crt1.o /usr/lib/x86_64-linux-gnu/crti.o /usr/lib/x86_64-linux-gnu/crtn.o -dynamic-linker /lib64/ld-linux-x86-64.so.2
```

## 3. Статическая и динамическая линковка

```bash
# Статическая линковка
g++ -static test.cpp

# Посмотреть зависимости от динамических библиотек
ldd a.out

# Сборка с библиотекой из нестандартного места
g++ test.cpp -L/path/to/lib -lmylib

# Создание динамической библиотеки
g++ -shared -fPIC lib.cpp -o libmy.so

# Использование LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/path/to/lib:$LD_LIBRARY_PATH

# Использование rpath
g++ test.cpp -Wl,-rpath,/path/to/lib -L/path/to/lib -lmy

# Посмотреть вызовы библиотечных функций
strace ./a.out
```

## 4. Формат ELF

```bash
# Посмотреть тип ELF файла
file a.out
file lib.so
file test.o

# Посмотреть секции
readelf -S a.out

# Использование objcopy
objcopy --only-keep-debug a.out a.out.debug
```

## 5. Символы и манглирование

```bash
# Посмотреть символы в объектном файле
nm test.o

# Демангировать имена символов
c++filt _Z3foov

# Сделать символы приватными
g++ -fvisibility=hidden test.cpp

# Посмотреть релокации
readelf -r test.o
```

## 6. Запуск программы

```bash
# Компиляция без _start
g++ -nostartfiles test.cpp

# Компиляция с явным указанием точки входа
g++ -e main test.cpp
```

## 7. Отладка с GDB

```bash
# Компиляция с отладочной информацией
g++ -g test.cpp

# Запуск отладчика
gdb ./a.out

# Основные команды GDB:
# break main - поставить breakpoint на функцию main
# run - запустить программу
# next/step - выполнить следующую строку
# print var - вывести значение переменной
# backtrace - показать стек вызовов
```

## 8. Системные вызовы

```bash
# Отслеживание системных вызовов
strace ./a.out

# Посмотреть man-страницу системного вызова
man 2 read

# Пример использования read/write
int fd = open("file.txt", O_RDONLY);
char buf[100];
ssize_t n = read(fd, buf, 100);
if (n < 0) {
    perror("read failed");
}
```

# Раздел 2. Файлы и файловые системы

## 9. Файловые дескрипторы и базовые операции с файлами

### Файловые дескрипторы
- Целочисленные идентификаторы открытых файлов в системе
- По умолчанию: 0 (stdin), 1 (stdout), 2 (stderr)
- Возвращаются системным вызовом open()

### Основные системные вызовы
```bash
# Открытие файла
open("file.txt", O_RDWR | O_CREAT, 0644)  # Возвращает файловый дескриптор
close(fd)  # Закрытие файла

# Перемещение по файлу
lseek(fd, offset, SEEK_SET)  # Абсолютное позиционирование
lseek(fd, offset, SEEK_CUR)  # Относительное от текущей позиции
lseek(fd, offset, SEEK_END)  # Относительно конца файла

# Чтение и запись
read(fd, buffer, count)   # Чтение count байт в buffer
write(fd, buffer, count)  # Запись count байт из buffer

# Пример копирования файла
while ((n = read(src_fd, buf, sizeof(buf))) > 0) {
    write(dst_fd, buf, n);
}
```

### Особенности работы с файловыми дескрипторами
- Проверка возвращаемых значений на ошибки
- Корректное закрытие файлов
- Обработка частичного чтения/записи

## 10. Перенаправление ввода-вывода

### Перенаправление в shell
```bash
# Перенаправление stdout в файл (перезапись)
command > output.txt

# Добавление stdout в конец файла
command >> output.txt

# Перенаправление stderr
command 2> error.txt

# Перенаправление обоих потоков
command &> output.txt

# Использование tee для записи и вывода
command | tee output.txt      # Вывод + запись
command | tee -a output.txt   # Вывод + добавление
```

### Системные вызовы для перенаправления
```c
dup(oldfd)    // Дублирует файловый дескриптор
dup2(oldfd, newfd)  // Дублирует oldfd в newfd

// Пример перенаправления stdout в файл
int fd = open("output.txt", O_WRONLY|O_CREAT, 0644);
dup2(fd, STDOUT_FILENO);
close(fd);
```

### Реализация команды tee
```c
int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_WRONLY|O_CREAT, 0644);
    char buf[4096];
    ssize_t n;
    
    while ((n = read(STDIN_FILENO, buf, sizeof(buf))) > 0) {
        write(STDOUT_FILENO, buf, n);  // Вывод в stdout
        write(fd, buf, n);             // Запись в файл
    }
    close(fd);
}
```
