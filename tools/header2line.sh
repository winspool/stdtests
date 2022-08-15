# !/bin/sh
#
# MAINTAINER_MODE - helper script to filter a header list:
# 
# * remove all comment lines
# * sort and remove duplicates
# * join header names to one line
#
#

file1=""
file2=""
opt_output=""
opt_raw=""
opt_debug="$DEBUG"


appname="`basename "$0" ".sh"`"

help_msg="$appname: [-h] [-o output] [-r] file1 [file2]
    -h          print this help
    -o output   write result to this file
    -r          write raw names
       file1    input file name
       [file2]  extra input file name" 



if [ "--help" = "$1" ]
then
    echo "$help_msg"
    exit 0
fi


while getopts h\?o:r  this_arg 
do

    if [ -n "$opt_debug" ]
    then
        echo "this_arg: $this_arg"
    fi

    case "$this_arg" in
    "h" | "?" )
        echo "$help_msg"
        exit 0
        ;;

    "o")
        opt_output="$OPTARG"
#       echo "opt_output set to: $opt_output"
        ;;

    "r")
        opt_raw="$this_arg"
#       echo "activated raw output"
        ;;

    esac

done

shift $((OPTIND-1))

this_arg="$1"

if [ -n "$this_arg" ]
then
    if [ -z "$file1" ]
    then
        file1="$this_arg"
#       echo "file1 set to: $file1"
        shift
        this_arg="$1"
    fi
fi

if [ -n "$this_arg" ]
then
    if [ -z "$file2" ]
    then
        file2="$this_arg"
#       echo "file2 set to: $file2"
        shift
        this_arg="$1"
    fi
fi


if [  -n "$this_arg"  -o  -z "$file1"  ]
then
    echo "$help_msg"
    exit 0
fi


if [ -z "$file1" ]
then
    echo "$help_msg
    no file"
    exit 0
fi

if [ -z "$file2" ]
then
    file2="/dev/null"
fi


include_names="`cat "$file1" "$file2"  | grep -v "^#" | sort -u | tr "\012" " " `"

#echo "opt_output: $opt_output"

if [ -z "$opt_raw" ]
then
    output_data="`echo  "AC_CHECK_HEADERS([$include_names])" `"
else
    output_data="$include_names"
fi


if [ -z "$opt_output" ]
then
    echo "$output_data" 
    if [ -n "$opt_debug" ] 
    then
        ls -al  "$file1" "$file2"
    fi
else
    echo "$output_data" | tee $opt_output >/dev/null
    if [ -n "$opt_debug" ] 
    then
        ls -al  "$file1" "$file2"  "$opt_output"
    fi
fi

# echo "### end of script"

