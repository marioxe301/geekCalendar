# geekCalendar

![calendario](https://github.com/marioxe301/geekCalendar/blob/master/img/format.png)

A lightweight, colorful terminal-based calendar application written in C++. Display monthly calendars with today's date highlighted in bold red, perfect for quick date checking right from your terminal.

## Features

- Display the current month calendar with today's date highlighted
- View any month and year by passing command-line parameters
- Colorful ANSI terminal interface with color-coded elements
- Lightweight and fast - no external dependencies
- Statically linked for maximum compatibility across Linux distributions
- Simple and intuitive command-line interface

## Installation

### From Release (Recommended)

1. Download the latest release tarball from the [Releases page](https://github.com/marioxe301/geekCalendar/releases)
2. Extract the tarball:
   ```bash
   tar -xzf gkcal-v1.0.0-linux-x86_64.tar.gz
   cd gkcal-v1.0.0-linux-x86_64
   ```
3. Verify the download (optional but recommended):
   ```bash
   sha256sum -c gkcal-v1.0.0-linux-x86_64.tar.gz.sha256
   ```
4. Install the binary:
   ```bash
   sudo install -m 755 gkcal /usr/local/bin/
   ```

### From Source

#### Prerequisites
- C++ compiler with C++11 support (g++ recommended)
- GNU Make

#### Build and Install
```bash
# Clone the repository
git clone https://github.com/marioxe301/geekCalendar.git
cd geekCalendar

# Build the binary
make

# Install to /usr/local/bin (requires sudo)
sudo make install
```

## Usage

### Display Current Month
Simply run the command without any arguments to display the current month's calendar with today's date highlighted:
```bash
gkcal
```

### Display Specific Month and Year
Pass the month (0-11) and year as arguments:
```bash
gkcal <month> <year>
```

**Examples:**
```bash
# Display January 2025
gkcal 0 2025

# Display December 2025
gkcal 11 2025

# Display March 2000
gkcal 2 2000
```

**Note:** Months are 0-indexed:
- 0 = January
- 1 = February
- 2 = March
- ...
- 11 = December

## Building from Source

### Available Make Targets

```bash
# Build the release binary (optimized)
make

# Build debug binary (with debug symbols)
make debug

# Install to system (requires sudo)
sudo make install

# Uninstall from system (requires sudo)
sudo make uninstall

# Create distribution tarball
make dist

# Clean build artifacts
make clean
```

### Compiler Flags
The release build uses the following optimizations:
- `-O2` - Optimization level 2
- `-Wall -Wextra` - Enable all warnings
- `-static-libgcc -static-libstdc++` - Static linking for portability

## Uninstallation

To remove the installed binary:
```bash
sudo make uninstall
```

Or manually:
```bash
sudo rm /usr/local/bin/gkcal
```

## Compatibility

This application is designed to work on all Linux distributions. The binary is statically linked with the C++ standard library, eliminating dependencies on specific library versions. It has been tested and works on:
- Ubuntu / Debian
- Fedora / CentOS / RHEL
- Arch Linux
- Alpine Linux
- And most other Linux distributions

## Development

### Project Structure
```
geekCalendar/
├── main.cpp        # Entry point and argument parsing
├── calendar.cpp    # Calendar logic and rendering
├── calendar.h      # Calendar class definition
├── colors.h        # ANSI color code definitions
├── makefile        # Build configuration
└── README.md       # This file
```

### Contributing
Contributions are welcome! Feel free to:
- Report bugs by opening an issue
- Suggest new features
- Submit pull requests

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

Free to use, modify, and distribute.

## Author

**Mario** - [@marioxe301](https://github.com/marioxe301)

## Acknowledgments

Built with C++ and a passion for terminal applications.
