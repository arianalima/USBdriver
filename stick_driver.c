#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>

//probe function 
static int pen_probe(struct usb_interface *interface, const struct usb_device_id *id){
    printk(KERN_INFO "[*] Ariana Pen drive (%04X:%04X) plugged\n", id->idVendor, id->idProduct);
    return 0;
}

//disconect
static void pen_disconnect(struct usb_interface *interface){
    printk(KERN_INFO "[*] Ariana Pen Drive removed\n");
}

//usb device_id
static struct usb_device_id pen_table[]={
    //3538:0901
    { USB_DEVICE(0x3538, 0x0901) },
    {}
};

MODULE_DEVICE_TABLE(usb, pen_table);

//usb driver
static struct usb_driver pen_driver = {
    .name = "Ariana-USB Stick-Driver",
    .id_table = pen_table,
    .probe = pen_probe,
    .disconnect = pen_disconnect,
};

static int __init pen_init(void){
    int ret = -1;
    printk(KERN_INFO "[*] Ariana Constructor of driver");
    printk(KERN_INFO "\tRegistering driver with kernel");
    ret = usb_register(&pen_driver);
    printk(KERN_INFO "\tRegistration is complete");
    return ret;
}

static void __exit pen_exit(void){
    //deregister
    printk(KERN_INFO "[*] Ariana destructor of driver");
    usb_deregister(&pen_driver);
    printk(KERN_INFO "\tunregisteration complete");
}

module_init(pen_init);
module_exit(pen_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ariana");
MODULE_DESCRIPTION("USB Pen Registration Driver");
