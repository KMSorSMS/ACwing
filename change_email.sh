#!/bin/sh


git filter-branch --env-filter '
OLD_EMAIL="liamyuan@liamdeMacBook-Air"
CORRECT_NAME="liam"
CORRECT_EMAIL="yzwliam@126.com"

# OLD_EMAIL="fphd_xian_lufei@fphd"
# CORRECT_NAME="sy-records"
# CORRECT_EMAIL="52o@qq52o.cn"

if [ "$GIT_COMMITTER_EMAIL" = "$OLD_EMAIL" ]
then
    export GIT_COMMITTER_NAME="$CORRECT_NAME"
    export GIT_COMMITTER_EMAIL="$CORRECT_EMAIL"
fi
if [ "$GIT_AUTHOR_EMAIL" = "$OLD_EMAIL" ]
then
    export GIT_AUTHOR_NAME="$CORRECT_NAME"
    export GIT_AUTHOR_EMAIL="$CORRECT_EMAIL"
fi
' --tag-name-filter cat -- --branches --tags