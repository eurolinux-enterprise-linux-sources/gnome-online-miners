%global _privatelibs libgom-1[.]0[.]so.*
%global __provides_exclude ^(%{_privatelibs})$
%global __requires_exclude ^(%{_privatelibs})$

Name:           gnome-online-miners
Version:        3.26.0
Release:        1%{?dist}
Summary:        Crawls through your online content

License:        GPLv2+ and LGPLv2+ and MIT
URL:            https://wiki.gnome.org/Projects/GnomeOnlineMiners
Source0:        https://download.gnome.org/sources/%{name}/3.26/%{name}-%{version}.tar.xz

# https://bugzilla.redhat.com/show_bug.cgi?id=985887
Patch0:         0001-zpj-Use-an-HTTP-URL-as-nie-url.patch

# https://bugzilla.redhat.com/show_bug.cgi?id=1568229
Patch1:         0001-Revert-build-Depend-on-libtracker-sparql-2.0.patch

BuildRequires:  autoconf
BuildRequires:  automake
BuildRequires:  glib2-devel >= 2.35.1
BuildRequires:  gnome-common
BuildRequires:  gnome-online-accounts-devel >= 3.8.0
BuildRequires:  libgdata-devel >= 0.15.2
BuildRequires:  libtool
BuildRequires:  libzapojit-devel >= 0.0.2
BuildRequires:  pkgconfig
BuildRequires:  tracker-devel >= 0.17.2

Requires:       dbus
Requires:       gvfs >= 1.18.3

%description
GNOME Online Miners provides a set of crawlers that go through your online
content and index them locally in Tracker. It has miners for Google, OneDrive
and ownCloud.


%prep
%setup -q
%patch0 -p1
%patch1 -p1


%build
autoreconf -f -i
%configure \
  --disable-silent-rules \
  --disable-static \
  --disable-facebook \
  --disable-flickr \
  --disable-media-server

make %{?_smp_mflags}


%install
%make_install
find $RPM_BUILD_ROOT -name '*.la' -delete

# Use %%doc instead.
rm -rf $RPM_BUILD_ROOT%{_docdir}/%{name}

rm -f $RPM_BUILD_ROOT%{_datadir}/dbus-1/services/org.gnome.OnlineMiners.Facebook.service
rm -f $RPM_BUILD_ROOT%{_datadir}/dbus-1/services/org.gnome.OnlineMiners.Flickr.service
rm -f $RPM_BUILD_ROOT%{_datadir}/dbus-1/services/org.gnome.OnlineMiners.MediaServer.service

%files
%license COPYING
%doc AUTHORS
%doc NEWS
%doc README
%{_datadir}/dbus-1/services/org.gnome.OnlineMiners.GData.service
%{_datadir}/dbus-1/services/org.gnome.OnlineMiners.Owncloud.service
%{_datadir}/dbus-1/services/org.gnome.OnlineMiners.Zpj.service

%dir %{_libdir}/%{name}
%{_libdir}/%{name}/libgom-1.0.so

%{_libexecdir}/gom-gdata-miner
%{_libexecdir}/gom-owncloud-miner
%{_libexecdir}/gom-zpj-miner


%changelog
* Mon Sep 11 2017 Kalev Lember <klember@redhat.com> - 3.26.0-1
- Update to 3.26.0
- Resolves: #1568229

* Mon Mar 27 2017 Debarshi Ray <rishi@fedoraproject.org> - 3.22.0-2
- Fix the nie:url for OneDrive entries
- Resolves: #985887, #1386954

* Mon Sep 19 2016 Kalev Lember <klember@redhat.com> - 3.22.0-1
- Update to 3.22.0
- Resolves: #1386954

* Tue May 05 2015 Debarshi Ray <rishi@fedoraproject.org> - 3.14.3-1
- Update to 3.14.3
Resolves: #1184195

* Tue Apr 14 2015 Debarshi Ray <rishi@fedoraproject.org> - 3.14.2-1
- Update to 3.14.2
- Disable unused miners - facebook, flickr and media-server
Resolves: #1184195

* Tue Dec 16 2014 Debarshi Ray <rishi@fedoraproject.org> - 3.14.1-1
- Update to 3.14.1
- Bump libgdata BuildRequires to reflect reality

* Wed Sep 24 2014 Kalev Lember <kalevlember@gmail.com> - 3.14.0-1
- Update to 3.14.0
- Ship NEWS instead of ChangeLog

* Wed Sep 03 2014 Kalev Lember <kalevlember@gmail.com> - 3.13.91-1
- Update to 3.13.91

* Sat Aug 16 2014 Fedora Release Engineering <rel-eng@lists.fedoraproject.org> - 3.13.3-2
- Rebuilt for https://fedoraproject.org/wiki/Fedora_21_22_Mass_Rebuild

* Wed Jun 25 2014 Richard Hughes <rhughes@redhat.com> - 3.13.3-1
- Update to 3.13.3

* Sat Jun 07 2014 Fedora Release Engineering <rel-eng@lists.fedoraproject.org> - 3.12.0-3
- Rebuilt for https://fedoraproject.org/wiki/Fedora_21_Mass_Rebuild

* Wed Apr 16 2014 Adam Williamson <awilliam@redhat.com> - 3.12.0-2
- rebuild for new libgdata

* Sun Mar 23 2014 Kalev Lember <kalevlember@gmail.com> - 3.12.0-1
- Update to 3.12.0

* Wed Feb 19 2014 Kalev Lember <kalevlember@gmail.com> - 3.11.90-1
- Update to 3.11.90

* Tue Feb 04 2014 Richard Hughes <rhughes@redhat.com> - 3.11.5-1
- Update to 3.11.5

* Mon Jan 20 2014 Debarshi Ray <rishi@fedoraproject.org> - 3.11.4-1
- Update to 3.11.4.

* Tue Dec 17 2013 Richard Hughes <rhughes@redhat.com> - 3.11.3-1
- Update to 3.11.3

* Fri Nov 22 2013 Debarshi Ray <rishi@fedoraproject.org> - 3.11.2-1
- Update to 3.11.2.

* Fri Nov 22 2013 Debarshi Ray <rishi@fedoraproject.org> - 3.10.2-1
- Update to 3.10.2.

* Wed Sep 25 2013 Kalev Lember <kalevlember@gmail.com> - 3.10.0-1
- Update to 3.10.0

* Wed Sep 18 2013 Kalev Lember <kalevlember@gmail.com> - 3.9.92-1
- Update to 3.9.92

* Tue Sep 03 2013 Kalev Lember <kalevlember@gmail.com> - 3.9.91-1
- Update to 3.9.91

* Thu Aug 22 2013 Debarshi Ray <rishi@fedoraproject.org> - 3.9.90-1
- Update to 3.9.90.

* Sat Aug 03 2013 Fedora Release Engineering <rel-eng@lists.fedoraproject.org> - 3.9.4-4
- Rebuilt for https://fedoraproject.org/wiki/Fedora_20_Mass_Rebuild

* Fri Jul 19 2013 Debarshi Ray <rishi@fedoraproject.org> - 3.9.4-3
- Filter out the private library from requires.

* Fri Jul 19 2013 Debarshi Ray <rishi@fedoraproject.org> - 3.9.4-2
- Use %%{_libexecdir}.
- Filter out the private library from provides.

* Tue Jul 09 2013 Debarshi Ray <rishi@fedoraproject.org> - 3.9.4-1
- Initial spec.
