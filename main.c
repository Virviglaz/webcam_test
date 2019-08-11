#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "framebuffer.h"

int main() {
	const char *device = "/dev/video0";
	const uint size = 640 * 480;
	int cam_fd;
	float data[size];
	int res = 0;
	
	printf("Opening framebuffer: %s\n", FrameBufferInit(NULL, 0));
	
	cam_fd = open(device, O_RDWR | O_NONBLOCK);
	if (cam_fd < 0) {
		res = errno;
		printf("Failed to open %s, error: %s\n",
			device, strerror(res));
		goto free_fb;
	}

	//if (read(data, sizeof(data[0]), size, camLive) != size)
		//printf("Error reading device %s\n", device);

	close(cam_fd);
	
free_fb:
	FrameBufferDeInit();
	return res;
}
