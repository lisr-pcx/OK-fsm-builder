"""OK-fsm-builder

This script generate C++ sourcecode of a FSM (Finite State Machine) described
in a text file (markdown). The user edits this file by defining: 
    - states
    - events (input)
    - transitions
    - actions (linked to elements above)

The text file is written in markdown to be easily managed between tools, and
can be also used as input for FSM related documentation.

The script will check the validity of the fileds, and then it will parse the
information provided to generate .h and .cpp files. Output will be available
in the desired folder.

For usage information please run:
$ python OK_fsm_builder.py --help
"""

# Created by: lisr-pcx (https://github.com/lisr-pcx/OK-fsm-builder)
# This is free software and it comes with absolutely no warranty.

import os
import argparse
import re
from datetime import datetime

# Use specific colors in terminal formatted output
class TerminalColors:
    BLUE = '\033[94m'
    CYAN = '\033[96m'
    GREEN = '\033[92m'
    YELLOW = '\033[93m'
    RED = '\033[91m'
    END = '\033[0m'

def create_arg_parser():
    """Creates and returns the ArgumentParser object"""

    parser = argparse.ArgumentParser(
                        prog='python.exe OK_fsm_builder.py',
                        description='Create C++ sourcecode of FSM based on configuration text file (Markdown).',
                        epilog='This is free software and it comes with absolutely no warranty.')
    parser.add_argument('config_file',
                        type=str,
                        help='Text file describing the FSM')
    parser.add_argument('-v', '--verbose',
                        action='store_true',
                        help='Show detailed logging (default is false).')
    return parser

if __name__ == "__main__":
    arguments = create_arg_parser()
    arguments_list = arguments.parse_args()    
    print(f"{TerminalColors.BLUE}OK-fsm-builder (2025){TerminalColors.END}")

    if not arguments_list.config_file:
        print(f"{TerminalColors.RED}Checking configuration file ...{TerminalColors.END}")
    else:
        print(f"{TerminalColors.BLUE}Checking configuration file ...{TerminalColors.END}")
        print(f"{TerminalColors.BLUE}[TODO]{TerminalColors.END}")

        print(f"{TerminalColors.BLUE}Parsing content ...{TerminalColors.END}")
        print(f"{TerminalColors.BLUE}[TODO]{TerminalColors.END}")
    print(f"{TerminalColors.BLUE}End{TerminalColors.END}\n")
