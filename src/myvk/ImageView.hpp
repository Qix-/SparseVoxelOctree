#ifndef MYVK_IMAGE_VIEW_HPP
#define MYVK_IMAGE_VIEW_HPP

#include "DeviceObjectBase.hpp"
#include "ImageBase.hpp"
#include "SwapchainImage.hpp"
#include <volk.h>
#include <memory>

namespace myvk {
	class ImageView : public DeviceObjectBase {
	private:
		std::shared_ptr<ImageBase> m_image_ptr;

		VkImageView m_image_view{nullptr};
	public:
		static std::shared_ptr<ImageView>
		Create(const std::shared_ptr<ImageBase> &image, const VkImageViewCreateInfo &create_info);

		static std::shared_ptr<ImageView> Create(const std::shared_ptr<ImageBase> &image,
												 VkImageViewType view_type, VkFormat format,
												 VkImageAspectFlags aspect_mask,
												 uint32_t base_mip_level = 0, uint32_t level_count = 1,
												 uint32_t base_array_layer = 0, uint32_t layer_count = 1,
												 const VkComponentMapping &components = {VK_COMPONENT_SWIZZLE_IDENTITY,
																						 VK_COMPONENT_SWIZZLE_IDENTITY,
																						 VK_COMPONENT_SWIZZLE_IDENTITY,
																						 VK_COMPONENT_SWIZZLE_IDENTITY});

		static std::shared_ptr<ImageView> Create(const std::shared_ptr<ImageBase> &image, VkImageViewType view_type,
												 VkImageAspectFlags aspect_mask = VK_IMAGE_ASPECT_COLOR_BIT);

		static std::shared_ptr<ImageView> Create(const std::shared_ptr<SwapchainImage> &swapchain_image);

		const std::shared_ptr<Device> &GetDevicePtr() const override { return m_image_ptr->GetDevicePtr(); };

		VkImageView GetHandle() const { return m_image_view; }

		~ImageView();
	};
}

#endif
