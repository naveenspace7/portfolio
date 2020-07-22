---
layout: post
title: A nice use case of Destructor
excerpt_separator: <!--more-->
tags: destructor C++
---

RAII is one of the important concepts of C++ and destructor plays a very crucial role. [One of the talks in CppCon](https://www.memsql.com/blog/c-error-handling-with-auto/) explains how the destructor can be used. 

<!--more-->

Imagine the following scenario, where the function can return early without reaching the end of the function, could be because of an exception or early return. If there is any action that needs to be done at the end of the function, but there's a possibility for an early return, there needs to be some additional checking mechanism to ensure the action is still perform eventually.


```c
logger* log;

class stop_logging {
    log* m_log;
    stop_logging(log* log_instance): m_log(log_instance) {
        m_log->pause_log();
    }
    ~stop_logging() {
        m_log->resume_log();
    }
}

bool heavy_duty_function() {
    stop_logging(logger);
    if (perform_action() < 0) return false;
    if (perform_another_action() < 0) return false;
    start_logging();
    return true;
}

int main() {
    bool success = heavy_duty_function();
}
```

The destructor ensures that the logger is re-enabled with the `stop_logging` goes out of scope. This reduces the amount of checking that needs to be done.