.section .init
    /* gcc will put the contents of crtend.o's .init here */
    popl %ebp
    ret

.section .fini
    /* gcc will put the crtend.o's .fini section herer */
    popl %ebp
    ret

