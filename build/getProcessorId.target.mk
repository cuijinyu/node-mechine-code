# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := getProcessorId
DEFS_Debug := \
	'-DNODE_GYP_MODULE_NAME=getProcessorId' \
	'-DUSING_UV_SHARED=1' \
	'-DUSING_V8_SHARED=1' \
	'-DV8_DEPRECATION_WARNINGS=1' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DDEBUG' \
	'-D_DEBUG' \
	'-DV8_ENABLE_CHECKS'

# Flags passed to all source files.
CFLAGS_Debug := \
	-fPIC \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-m64 \
	-g \
	-O0

# Flags passed to only C files.
CFLAGS_C_Debug :=

# Flags passed to only C++ files.
CFLAGS_CC_Debug := \
	-fno-rtti \
	-fno-exceptions \
	-std=gnu++1y

INCS_Debug := \
	-I/home/cuijinyu/.node-gyp/10.9.0/include/node \
	-I/home/cuijinyu/.node-gyp/10.9.0/src \
	-I/home/cuijinyu/.node-gyp/10.9.0/deps/openssl/config \
	-I/home/cuijinyu/.node-gyp/10.9.0/deps/openssl/openssl/include \
	-I/home/cuijinyu/.node-gyp/10.9.0/deps/uv/include \
	-I/home/cuijinyu/.node-gyp/10.9.0/deps/zlib \
	-I/home/cuijinyu/.node-gyp/10.9.0/deps/v8/include

DEFS_Release := \
	'-DNODE_GYP_MODULE_NAME=getProcessorId' \
	'-DUSING_UV_SHARED=1' \
	'-DUSING_V8_SHARED=1' \
	'-DV8_DEPRECATION_WARNINGS=1' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64'

# Flags passed to all source files.
CFLAGS_Release := \
	-fPIC \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-m64 \
	-O3 \
	-fno-omit-frame-pointer

# Flags passed to only C files.
CFLAGS_C_Release :=

# Flags passed to only C++ files.
CFLAGS_CC_Release := \
	-fno-rtti \
	-fno-exceptions \
	-std=gnu++1y

INCS_Release := \
	-I/home/cuijinyu/.node-gyp/10.9.0/include/node \
	-I/home/cuijinyu/.node-gyp/10.9.0/src \
	-I/home/cuijinyu/.node-gyp/10.9.0/deps/openssl/config \
	-I/home/cuijinyu/.node-gyp/10.9.0/deps/openssl/openssl/include \
	-I/home/cuijinyu/.node-gyp/10.9.0/deps/uv/include \
	-I/home/cuijinyu/.node-gyp/10.9.0/deps/zlib \
	-I/home/cuijinyu/.node-gyp/10.9.0/deps/v8/include

OBJS := \
	$(obj).target/$(TARGET)//src/getProcessorId.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# End of this set of suffix rules
### Rules for final target.
LDFLAGS_Debug := \
	-pthread \
	-rdynamic \
	-m64

LDFLAGS_Release := \
	-pthread \
	-rdynamic \
	-m64

LIBS :=

$(obj).target/getProcessorId.a: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(obj).target/getProcessorId.a: LIBS := $(LIBS)
$(obj).target/getProcessorId.a: TOOLSET := $(TOOLSET)
$(obj).target/getProcessorId.a: $(OBJS) FORCE_DO_CMD
	$(call do_cmd,alink)

all_deps += $(obj).target/getProcessorId.a
# Add target alias
.PHONY: getProcessorId
getProcessorId: $(obj).target/getProcessorId.a

# Add target alias to "all" target.
.PHONY: all
all: getProcessorId

# Add target alias
.PHONY: getProcessorId
getProcessorId: $(builddir)/getProcessorId.a

# Copy this to the static library output path.
$(builddir)/getProcessorId.a: TOOLSET := $(TOOLSET)
$(builddir)/getProcessorId.a: $(obj).target/getProcessorId.a FORCE_DO_CMD
	$(call do_cmd,copy)

all_deps += $(builddir)/getProcessorId.a
# Short alias for building this static library.
.PHONY: getProcessorId.a
getProcessorId.a: $(obj).target/getProcessorId.a $(builddir)/getProcessorId.a

# Add static library to "all" target.
.PHONY: all
all: $(builddir)/getProcessorId.a

