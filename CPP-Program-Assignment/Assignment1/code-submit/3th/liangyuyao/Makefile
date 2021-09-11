BUILD_DIR = build
BIN = Assignment1_pro.out

.PHONY:

run:clean
	cmake . -B $(BUILD_DIR)
	make -C $(BUILD_DIR)
	cd $(BUILD_DIR) && ./$(BIN)

build:clean
	cmake . -B $(BUILD_DIR) -Ddebug=1
	make -C $(BUILD_DIR)
	cd $(BUILD_DIR)

gdb:build
	cd $(BUILD_DIR) && gdb $(BIN)

clean:
	rm -rf $(BUILD_DIR)