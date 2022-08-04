#!/bin/sh

user_opts="$*"

verbose_mode=""
subdir_mode="--no-recursive"

# autoconf supports env variable WARNING
# when not set, disable all warnings for the user

if [ -n "$WARNINGS" ]
then
echo "found WARNINGS: $WARNINGS"
verbose_mode="--verbose"
fi

if [ -z "$WARNINGS" ]
then
WARNINGS="none"
verbose_mode=""
fi


# maintainer should see all warnings
# probably bail out with an error
# 
if [ -n "$MAINTAINER_MODE" -o -n "$MAINTAINERMODE" ]
then
WARNINGS="all"
verbose_mode=" --verbose"
echo "MAINTAINER_MODE activated: $MAINTAINER_MODE / $MAINTAINERMODE"
fi

export WARNINGS="$WARNINGS"


# autoreconf supported commandline parameter example:
# long:  --warnings=all
# short: -Wall
exec autoreconf $verbose_mode $subdir_mode $user_opts


