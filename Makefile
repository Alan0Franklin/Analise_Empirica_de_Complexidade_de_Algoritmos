# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -O0 -pedantic -I$(INCLUDE_DIR)

# Diretórios
SRC_DIR = src_cpp
INCLUDE_DIR = include_hpp
OBJ_DIR = obj

# Arquivos fonte e objeto
EXEC = Analise_Empirica_de_Complexidade_de_Algoritmos.exe
SRCS = $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(filter $(SRC_DIR)/%.cpp,$(SRCS))) $(OBJ_DIR)/main.o
#OBJS += $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(filter %.cpp,$(SRCS)))

# Compilação do executável
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Criação do diretório obj, se não existir
$(OBJ_DIR):
	mkdir $(OBJ_DIR): main.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilação de cada .cpp em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -f $(SRC_DIR)/*.o $(EXEC)

clean-windows:
	@if exist $(OBJ_DIR)\*.o del /Q $(OBJ_DIR)\*.o
	@if exist $(EXEC) del /Q $(EXEC)