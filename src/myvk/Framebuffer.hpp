#ifndef MYVK_FRAMEBUFFER_HPP
#define MYVK_FRAMEBUFFER_HPP

#include "DeviceObjectBase.hpp"
#include "RenderPass.hpp"
#include "ImageView.hpp"

#include <memory>
#include <vector>

namespace myvk {
	class Framebuffer : public DeviceObjectBase {
	private:
		std::shared_ptr<RenderPass> m_render_pass_ptr;
		std::vector<std::shared_ptr<ImageView>> m_image_view_ptrs;

		VkFramebuffer m_framebuffer{nullptr};

	public:
		static std::shared_ptr<Framebuffer> Create(const std::shared_ptr<RenderPass> &render_pass,
												   const std::vector<std::shared_ptr<ImageView>> &image_views,
												   const VkExtent2D &extent, uint32_t layers = 1,
												   VkFramebufferCreateFlags flags = 0);

		VkFramebuffer GetHandle() const { return m_framebuffer; }

		const std::shared_ptr<Device> &GetDevicePtr() const override { return m_render_pass_ptr->GetDevicePtr(); }

		const std::shared_ptr<RenderPass> &GetRenderPassPtr() const { return m_render_pass_ptr; }

		const std::vector<std::shared_ptr<ImageView>> &GetImageViewPtrs() const { return m_image_view_ptrs; }

		~Framebuffer();
	};
}

#endif
