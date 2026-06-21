/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "OffscreenCanvasRenderingContext2D.h"

#include "mozilla/dom/OffscreenCanvas.h"
#include "mozilla/dom/OffscreenCanvasRenderingContext2DBinding.h"

using namespace mozilla;

namespace mozilla::dom {

NS_IMPL_CYCLE_COLLECTION_INHERITED(OffscreenCanvasRenderingContext2D,
                                   CanvasRenderingContext2D)

NS_IMPL_ISUPPORTS_CYCLE_COLLECTION_INHERITED_0(
    OffscreenCanvasRenderingContext2D, CanvasRenderingContext2D)

// Need to use NS_DECL_CYCLE_COLLECTION_SKIPPABLE_SCRIPT_HOLDER_CLASS_INHERITED
// and dummy trace since we're missing some _SKIPPABLE_ macros without
// SCRIPT_HOLDER.
NS_IMPL_CYCLE_COLLECTION_TRACE_BEGIN_INHERITED(
    OffscreenCanvasRenderingContext2D, CanvasRenderingContext2D)
NS_IMPL_CYCLE_COLLECTION_TRACE_END

NS_IMPL_CYCLE_COLLECTION_CAN_SKIP_BEGIN(OffscreenCanvasRenderingContext2D)
  return tmp->HasKnownLiveWrapper();
NS_IMPL_CYCLE_COLLECTION_CAN_SKIP_END

NS_IMPL_CYCLE_COLLECTION_CAN_SKIP_IN_CC_BEGIN(OffscreenCanvasRenderingContext2D)
  return tmp->HasKnownLiveWrapper();
NS_IMPL_CYCLE_COLLECTION_CAN_SKIP_IN_CC_END

NS_IMPL_CYCLE_COLLECTION_CAN_SKIP_THIS_BEGIN(OffscreenCanvasRenderingContext2D)
  return tmp->HasKnownLiveWrapper();
NS_IMPL_CYCLE_COLLECTION_CAN_SKIP_THIS_END

OffscreenCanvasRenderingContext2D::~OffscreenCanvasRenderingContext2D() =
    default;

JSObject* OffscreenCanvasRenderingContext2D::WrapObject(
    JSContext* aCx, JS::Handle<JSObject*> aGivenProto) {
  return OffscreenCanvasRenderingContext2D_Binding::Wrap(aCx, this,
                                                         aGivenProto);
}

NS_IMETHODIMP OffscreenCanvasRenderingContext2D::InitializeWithDrawTarget(
    nsIDocShell* aShell, NotNull<gfx::DrawTarget*> aTarget) {
  return NS_ERROR_NOT_IMPLEMENTED;
}

void OffscreenCanvasRenderingContext2D::Commit(ErrorResult& aRv) {
  if (!mOffscreenCanvas->IsTransferredFromElement()) {
    return;
  }

  mOffscreenCanvas->CommitFrameToCompositor();
}

}  // namespace mozilla::dom
