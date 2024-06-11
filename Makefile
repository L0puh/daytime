CC=gcc
BUILD_DIR=build
SOURCES=$(wildcard src/*.c)

$(BUILD_DIR)/%.o: src/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) -c -o $@ $< -Iinclude 


all: client server

client: $(patsubst src/%.c, $(BUILD_DIR)/%.o, $(filter-out %server.c, $(SOURCES)))
	$(CC) -o $@ $^ -Iinclude

server: $(patsubst src/%.c, $(BUILD_DIR)/%.o, $(filter-out %client.c, $(SOURCES)))
	$(CC) -o $@ $^ -Iinclude

clean:
	rm -rf $(BUILD_DIR)/* server client
