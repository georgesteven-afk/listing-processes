#include <linux/sched/signal.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

int startup(void) {

	struct task_struct *task;
	
	printk(KERN_INFO "Loading taskManager module \n");
	
	printk(KERN_INFO "----------TASK MANAGER---------- \n");
	
	for(task=current;task!=&init_task;task=task->parent)
	{
	
		printk(KERN_INFO "Process: %-20s State: %ld\tProcess ID: %d\n", task->comm, task->state, task->pid);
	
	}
	printk(KERN_INFO "Task Manager closed\n");
	return 0;
}

void cleanup(void) {

	printk(KERN_INFO "Cleaning up Task Managern");

}

module_init(startup);
module_exit(cleanup);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Display tasks running in Linux");
