#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>
#include "framebuffer.h"

int main() {
	const char *device = "/dev/video0";
	const uint size = 640 * 480;
	int cam_fd;
	float data[size];
	int res = 0;
	struct v4l2_capability capability;
	
	printf("Opening framebuffer: %s\n", FrameBufferInit(NULL, 0));
	
	cam_fd = open(device, O_RDWR | O_NONBLOCK);
	if (cam_fd < 0) {
		res = errno;
		printf("Failed to open %s, error: %s\n",
			device, strerror(res));
		goto free_fb;
	}

	if (ioctl(cam_fd, VIDIOC_QUERYCAP, &capability)) {
		res = errno;
		printf("Failed to do IOCTL %s, error: %s\n",
			device, strerror(res));	
		goto close_cam;
	}

	printf("Camera name: %s\n", capability.card);

	//if (read(data, sizeof(data[0]), size, camLive) != size)
		//printf("Error reading device %s\n", device);

close_cam:
	close(cam_fd);
	
free_fb:
	FrameBufferDeInit();
	return res;
}
