The command to build:

cmake -B build -S . && cd build && make


Usage: ./nmap2joplin [OPTIONS]
Options:
  -f, --file       Set the path to a single XML file for processing.
  -s, --files      Set the path to multiple XML files for processing separated by spaces.
  -d, --directory  Set the path to the output directory where results will be stored.
  -h, --help       Display this help message and exit.

Example:

./nmap2joplin -f <path to the file> -d <directory to save>
