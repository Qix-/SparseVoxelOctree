#ifndef MYVK_BUFFER_BASE_HPP
#define MYVK_BUFFER_BASE_HPP

#include <volk.h>
#include "DeviceObjectBase.hpp"

namespace myvk {
	struct BufferSubresourceRange {
		VkDeviceSize size, offset;
	};

	class BufferBase : public DeviceObjectBase {
	protected:
		VkBuffer m_buffer{nullptr};
		VkDeviceSize m_size{0};

	public:
		VkBuffer GetHandle() const { return m_buffer; }

		VkDeviceSize GetSize() const { return m_size; }

		std::vector<VkBufferMemoryBarrier>
		GetMemoryBarriers(const std::vector<BufferSubresourceRange> &regions,
						  VkAccessFlags src_access_mask, VkAccessFlags dst_access_mask);

		std::vector<VkBufferMemoryBarrier>
		GetSrcMemoryBarriers(const std::vector<VkBufferCopy> &regions,
							 VkAccessFlags src_access_mask, VkAccessFlags dst_access_mask);

		std::vector<VkBufferMemoryBarrier>
		GetDstMemoryBarriers(const std::vector<VkBufferCopy> &regions,
							 VkAccessFlags src_access_mask, VkAccessFlags dst_access_mask);

		std::vector<VkBufferMemoryBarrier> GetSrcMemoryBarriers(const std::vector<VkBufferImageCopy> &regions,
																VkAccessFlags src_access_mask,
																VkAccessFlags dst_access_mask);
	};
}


#endif
