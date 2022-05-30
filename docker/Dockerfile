# Basic instructions to build container and push to Docker Hub repository:
#
# Build:            > docker build -t [container_name] -f Dockerfile .
# Tag to remote:    > docker tag [container_name]:latest [dockerhub_repo]:[tag_name]
# Push to remote:   > docker push [container_name]:[tag_name]

# Base image
FROM debian:bullseye-slim

# Install Ubuntu packages.
RUN apt-get update && DEBIAN_FRONTEND="noninteractive" apt-get install -y \
    git \
    python3-pip \
    tzdata \
    uncrustify \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Install Python packages.
RUN pip3 install --upgrade pip \
    && pip3 install black

# Create default user, due to:
#   - Build and test artifacts have user permissions and not root permissions
#   - Don't give root privileges from host to containers (security)
ARG USER=user
ARG UID=1000
ARG GID=1000
RUN useradd -m ${USER} --uid=${UID}
USER ${UID}:${GID}

# Note: Project repo is cloned in the `build` directory in BitBucket pipeline.
# Project workspace
WORKDIR /project
