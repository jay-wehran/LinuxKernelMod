#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>

MODULE_LICENSE("GPL"); //*
MODULE_AUTHOR("Jason Wehran"); //*
MODULE_DESCRIPTION("Basic read loadbale kernel module"); //*

static struct proc_dir_entry *custom_proc_node;

static ssize_t j_read(struct file* file_pointer, char *user_space_buffer, size_t count, loff_t* offset) {



    char msg[] = "Ack!\n";
    size_t len = strlen(msg);
    int result;
    printk("j_read\n");

    if (*offset >= len) { return 0;}


    result = copy_to_user(user_space_buffer,msg,len);
    *offset += len;


    return len;
}

struct proc_ops driver_proc_ops = {
    .proc_read = j_read

};

static int j_module_init (void) {
    printk("J_module_init: entry\n");

    custom_proc_node = proc_create("j_driver", 0, NULL, &driver_proc_ops);

    
    
    
    printk("j_module_init: exit\n");
    return 0;
}

static void j_module_exit(void) {
    printk("j_module_exit: entry\n");

    proc_remove(custom_proc_node);

    printk("j_module_exit: exit\n");
}

module_init(j_module_init);
module_exit(j_module_exit);
