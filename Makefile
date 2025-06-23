# Makefile para o projeto Super Trunfo

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

# Nome do executável
TARGET = $(BINDIR)/super_trunfo

# Arquivos fonte
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Regra principal
all: directories $(TARGET)

# Criar diretórios necessários
directories:
	@mkdir -p $(OBJDIR) $(BINDIR)

# Compilar o executável
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
	@chmod +x $@
	@echo "Compilação concluída! Execute com: ./$(TARGET)"
	@echo "Ou use: make run"

# Compilar arquivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Limpar arquivos compilados
clean:
	rm -rf $(OBJDIR) $(BINDIR)
	@echo "Arquivos limpos!"

# Executar o programa (com verificação de permissões)
run: $(TARGET)
	@chmod +x $(TARGET) 2>/dev/null || true
	./$(TARGET)

# Instalar (copiar para /usr/local/bin) - opcional
install: $(TARGET)
	@echo "Instalando Super Trunfo..."
	@sudo cp $(TARGET) /usr/local/bin/super_trunfo
	@sudo chmod +x /usr/local/bin/super_trunfo
	@echo "Instalação concluída! Agora você pode executar 'super_trunfo' de qualquer lugar."

# Desinstalar
uninstall:
	@sudo rm -f /usr/local/bin/super_trunfo
	@echo "Super Trunfo desinstalado."

# Verificar permissões
check-permissions:
	@echo "Verificando permissões do executável..."
	@ls -la $(TARGET) 2>/dev/null || echo "Arquivo não encontrado. Execute 'make' primeiro."

# Corrigir permissões
fix-permissions: $(TARGET)
	@echo "Corrigindo permissões..."
	@chmod +x $(TARGET)
	@echo "Permissões corrigidas!"

# Debug - mostrar informações de compilação
debug:
	@echo "Diretório fonte: $(SRCDIR)"
	@echo "Diretório include: $(INCDIR)"
	@echo "Arquivos fonte: $(SOURCES)"
	@echo "Arquivos objeto: $(OBJECTS)"
	@echo "Executável: $(TARGET)"
	@echo "Flags do compilador: $(CFLAGS)"

# Regras que não correspondem a arquivos
.PHONY: all clean run directories install uninstall check-permissions fix-permissions debug help

# Informações de ajuda
help:
	@echo "Super Trunfo - Comandos disponíveis:"
	@echo ""
	@echo "  make                 - Compila o projeto"
	@echo "  make run             - Compila e executa o programa"
	@echo "  make clean           - Remove arquivos compilados"
	@echo "  make check-permissions - Verifica permissões do executável"
	@echo "  make fix-permissions - Corrige permissões do executável"
	@echo "  make install         - Instala o programa no sistema"
	@echo "  make uninstall       - Remove o programa do sistema"
	@echo "  make debug           - Mostra informações de debug"
	@echo "  make help            - Mostra esta ajuda"
	@echo ""
	@echo "Comandos de execução rápida:"
	@echo "  chmod +x bin/super_trunfo && ./bin/super_trunfo"