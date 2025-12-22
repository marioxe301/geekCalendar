# geekCalendar Makefile
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -O2 -Wall -Wextra
LDFLAGS = -static-libgcc -static-libstdc++

# Target binary
TARGET = gkcal

# Source files
SOURCES = main.cpp calendar.cpp
HEADERS = calendar.h colors.h

# Installation paths
PREFIX = /usr/local
BINDIR = $(PREFIX)/bin

# Version (can be overridden by CI: make VERSION=1.0.0)
VERSION = 1.0.0

# Distribution name
DIST_NAME = $(TARGET)-v$(VERSION)-linux-x86_64

# Phony targets (not actual files)
.PHONY: all clean install uninstall dist debug help

# Default target
all: $(TARGET)

# Build the release binary
$(TARGET): $(SOURCES) $(HEADERS)
	@echo "Building $(TARGET) (release)..."
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SOURCES) -o $(TARGET)
	@echo "Build complete: ./$(TARGET)"

# Build debug version
debug: CXXFLAGS = -std=c++11 -g -Wall -Wextra
debug: LDFLAGS =
debug: clean
debug: $(TARGET)
	@echo "Debug build complete: ./$(TARGET)"

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	@rm -f $(TARGET)
	@rm -f $(DIST_NAME).tar.gz
	@rm -f $(DIST_NAME).tar.gz.sha256
	@rm -rf $(DIST_NAME)
	@echo "Clean complete."

# Install to system (requires sudo)
install: $(TARGET)
	@echo "Installing $(TARGET) to $(BINDIR)..."
	@if [ "$$(id -u)" -ne 0 ]; then \
		echo "Error: Installation requires root privileges."; \
		echo "Please run: sudo make install"; \
		exit 1; \
	fi
	@install -d $(BINDIR)
	@install -m 755 $(TARGET) $(BINDIR)/$(TARGET)
	@echo "Installation complete!"
	@echo "You can now run '$(TARGET)' from anywhere."

# Uninstall from system (requires sudo)
uninstall:
	@echo "Uninstalling $(TARGET) from $(BINDIR)..."
	@if [ "$$(id -u)" -ne 0 ]; then \
		echo "Error: Uninstallation requires root privileges."; \
		echo "Please run: sudo make uninstall"; \
		exit 1; \
	fi
	@if [ -f $(BINDIR)/$(TARGET) ]; then \
		rm -f $(BINDIR)/$(TARGET); \
		echo "Uninstallation complete."; \
	else \
		echo "$(TARGET) is not installed in $(BINDIR)."; \
	fi

# Create distribution tarball
dist: $(TARGET)
	@echo "Creating distribution tarball..."
	@mkdir -p $(DIST_NAME)
	@cp $(TARGET) README.md LICENSE $(DIST_NAME)/
	@tar -czf $(DIST_NAME).tar.gz $(DIST_NAME)
	@rm -rf $(DIST_NAME)
	@echo "Created: $(DIST_NAME).tar.gz"
	@ls -lh $(DIST_NAME).tar.gz

# Show help
help:
	@echo "geekCalendar Build System"
	@echo ""
	@echo "Available targets:"
	@echo "  make          - Build the release binary (default)"
	@echo "  make debug    - Build debug binary with symbols"
	@echo "  make clean    - Remove build artifacts"
	@echo "  make install  - Install to $(BINDIR) (requires sudo)"
	@echo "  make uninstall- Remove from $(BINDIR) (requires sudo)"
	@echo "  make dist     - Create distribution tarball"
	@echo "  make help     - Show this help message"
	@echo ""
	@echo "Examples:"
	@echo "  make && sudo make install"
	@echo "  make clean && make debug"
	@echo "  make dist VERSION=1.0.0"