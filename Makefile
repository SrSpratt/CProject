# Dossiers
SRC_DIR := .
APP_DIR := $(SRC_DIR)/Application
OBJ_DIR := $(SRC_DIR)/Object
LIB_DIR := $(SRC_DIR)/Libs
BUILD_DIR := $(SRC_DIR)/Build

# Fichiers
SRCS := $(wildcard *.c)
SRC := $(wildcard $(SRC_DIR)/*.c)
APP := $(wildcard $(APP_DIR)/**/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) $(APP:$(APP_DIR)/%.c=$(OBJ_DIR)/%.o)
EXEC := $(BUILD_DIR)/app.exe

# Compilateur et les drapeaux
CC := gcc
CFLAGS := -I $(LIB_DIR)

# Cibles
print:
	@echo $(LIB_DIR)
	@echo $(APP_DIR)
	@echo $(APP)

all: buildDir $(EXEC)

# Créer les répertoires nécessaires
buildDir:
	@powershell -Command "if (-Not (Test-Path -Path '$(OBJ_DIR)')) {New-Item -ItemType Directory -Path '$(OBJ_DIR)' }"
	@powershell -Command "if (-Not (Test-Path -Path '$(BUILD_DIR)')) {New-Item -ItemType Directory -Path '$(BUILD_DIR)' }"

# Compilation des fichiers .c en .o dans le répertoire SRC
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@powershell -Command "if (-Not (Test-Path -Path '$(dir $@)')) { New-Item -ItemType Directory -Path '$(dir $@)' }"
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation des fichiers .c en .o dans le répertoire APP
$(OBJ_DIR)/%.o : $(APP_DIR)/%.c
	@powershell -Command "if (-Not (Test-Path -Path '$(dir $@)')) { New-Item -ItemType Directory -Path '$(dir $@)' }"
	$(CC) $(CFLAGS) -c $< -o $@

# Lier les fichiers objets pour créer l'exécutable
$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Nettoyage
cleanObj:
	@powershell -Command "if (Test-Path '$(OBJ_DIR)') { Remove-Item -Recurse -Force '$(OBJ_DIR)/*' }"
clean:
	@powershell -Command "if (Test-Path '$(OBJ_DIR)') { Remove-Item -Recurse -Force '$(OBJ_DIR)/*' }"
	@powershell -Command "if (Test-Path '$(EXEC)') { Remove-Item -Force '$(EXEC)' }"

run:
	@powershell -Command "echo 'Running...'"
	@powershell -Command "$(BUILD_DIR)/app.exe"

.PHONY: all clean cleanObj run