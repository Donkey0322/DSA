CC = gcc
CFLAGS = -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lcriterion
TARGET = test  # 可執行檔名稱
.PHONY: run clean

$(TARGET): test.c
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) test.c

run: $(TARGET)
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) test.c
	@./$(TARGET)

clean:
	rm -f $(TARGET)