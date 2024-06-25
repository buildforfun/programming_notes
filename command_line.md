
#### File paths
- absolute paths begin from the top of directory tree: /
- relative path 
  - from current directory: .
  - from parent directory: ..
- full file path: pwd
- home directory is the filepath your terminal starts

### Other useful commands
- list file names: ls
- changing directories: cd
- inspect file quickly from terminal: head or tail
- create a file and edit: nano file_name.txt
- copy file: cp old_file.txt new_file.txt
- interatively copy: cp - i old_path/* new_path/
- move the file (doesn't keep original): mv old_file.txt new_file.txt
- making directories: mkdir
- deleting files and directories: rm

#### redirections and pipes
- to redirect terminal output by creating a new file + overwrite: >
- to redirect terminal output by appending to a file: >>
- pipe command lets you chain commands, output of one file is input to another command: head -1 file.txt | tail -1 

### sharing and permissions
- connect to another computer: ssh
- send files to another computer: scp
- seeing file permissions: ls -l
- change permissions: chown and chmod

### bash scripts
file ends with .sh
allows you to run multiple commands in one go
example: nano test.sh 
once you put command in and save, you need to make it exectuable:
chmod a+x test.sh
to exectute, run with full path or path environment variable:
./test.sh