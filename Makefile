CC=gcc
BUILD_DIR=build
SOURCES=$(wildcard src/*.c)


$(BUILD_DIR)/%.o: src/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) -c -o $@ $< -Iinclude 

daytime: $(patsubst src/%.c, $(BUILD_DIR)/%.o, $(SOURCES))
	$(CC) -o $@ $^ -Iinclude

clean:
	rm -rf $(BUILD_DIR)/* daytime
