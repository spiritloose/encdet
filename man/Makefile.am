man_MANS = encdet.3
EXTRA_DIST = $(man_MANS) encdet.3.pod
MAINTAINERCLEANFILES = $(man_MANS)

$(man_MANS): encdet.3.pod
	pod2man --center="$(PACKAGE_NAME)" \
			--release="$(PACKAGE_NAME) $(PACKAGE_VERSION)" \
			--date="`date +'%B %Y'`" \
			$< > $@
