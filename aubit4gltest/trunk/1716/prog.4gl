main
        run "echo 1 > /tmp/wait.1; sleep 40" waiting for 5 by 1 with error "Waiting"
        run "echo 1 > /tmp/wait.2;sleep 40" waiting for 5 by 1 with message "Waiting"
        run "echo 1 > /tmp/wait.3; sleep 40" waiting for 5 with message "Waiting"
        run "echo 1 > /tmp/wait.4; sleep 40" waiting for 5 with error "Waiting"
end main

