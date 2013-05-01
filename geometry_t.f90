#define NCELLS 636268
#define NSURFACES 636257

module xml_data_geometry_t
   use READ_XML_PRIMITIVES
   use WRITE_XML_PRIMITIVES
   use XMLPARSE
   implicit none
   save
   integer, private :: lurep_
   logical, private :: strict_
   integer :: jrt_cell_size
   integer :: jrt_surf_size

type cell_xml
   integer                                         :: id
   integer                                         :: universe
   character(len=12)                                :: material
   integer                                         :: fill
   integer, dimension(:), pointer                  :: surfaces => null()
   real(kind=kind(1.0d0)), dimension(:), pointer   :: rotation => null()
   real(kind=kind(1.0d0)), dimension(:), pointer   :: translation => null()
end type cell_xml

type surface_xml
   integer                                         :: id
   character(len=15)                                :: type
   real(kind=kind(1.0d0)), dimension(:), pointer   :: coeffs => null()
   character(len=12)                                :: boundary
end type surface_xml

type lattice_xml
   integer                                         :: id
   character(len=12)                                :: type
   integer, dimension(:), pointer                  :: dimension => null()
   real(kind=kind(1.0d0)), dimension(:), pointer   :: lower_left => null()
   real(kind=kind(1.0d0)), dimension(:), pointer   :: width => null()
   integer, dimension(:), pointer                  :: universes => null()
end type lattice_xml
   type(cell_xml), dimension(:), pointer           :: cell_ => null()
   type(surface_xml), dimension(:), pointer        :: surface_ => null()
   type(lattice_xml), dimension(:), pointer        :: lattice_ => null()
contains

! This one and the surface one are the real hogs
subroutine read_xml_type_cell_xml_array( &
      info, tag, endtag, attribs, noattribs, data, nodata, &
      dvar, has_dvar )
   type(XML_PARSE)                                 :: info
   character(len=*), intent(inout)                 :: tag
   logical, intent(inout)                          :: endtag
   character(len=*), dimension(:,:), intent(inout) :: attribs
   integer, intent(inout)                          :: noattribs
   character(len=*), dimension(:), intent(inout)   :: data
   integer, intent(inout)                          :: nodata
   type(cell_xml), dimension(:), pointer :: dvar
   logical, intent(inout)                       :: has_dvar

   integer                                      :: newsize
   type(cell_xml), dimension(:), pointer :: newvar
	
	jrt_cell_size = jrt_cell_size + 1
	
!	   newsize = size(dvar) + 1
	   
!	if( jrtsize > newsize ) then

!	   allocate( newvar(1:newsize+1000) )
!	   newvar(1:newsize-1000) = dvar
!	   deallocate( dvar )
!	   dvar => newvar
	
!	endif




   call read_xml_type_cell_xml( info, tag, endtag, attribs, noattribs, data, nodata, &
              dvar(jrt_cell_size), has_dvar )
end subroutine read_xml_type_cell_xml_array

subroutine read_xml_type_cell_xml( info, starttag, endtag, attribs, noattribs, data, nodata, &
              dvar, has_dvar )
   type(XML_PARSE)                                 :: info
   character(len=*), intent(in)                    :: starttag
   logical, intent(inout)                          :: endtag
   character(len=*), dimension(:,:), intent(inout) :: attribs
   integer, intent(inout)                          :: noattribs
   character(len=*), dimension(:), intent(inout)   :: data
   integer, intent(inout)                          :: nodata
   type(cell_xml), intent(inout)  :: dvar
   logical, intent(inout)                       :: has_dvar

   integer                                      :: att_
   integer                                      :: noatt_
   logical                                      :: error
   logical                                      :: endtag_org
   character(len=len(starttag))                 :: tag
   logical                                         :: has_id
   logical                                         :: has_universe
   logical                                         :: has_material
   logical                                         :: has_fill
   logical                                         :: has_surfaces
   logical                                         :: has_rotation
   logical                                         :: has_translation
   has_id                               = .false.
   has_universe                         = .false.
   has_material                         = .false.
   has_fill                             = .false.
   has_surfaces                         = .false.
   has_rotation                         = .false.
   has_translation                      = .false.
   call init_xml_type_cell_xml(dvar)
   has_dvar = .true.
   error  = .false.
   att_   = 0
   noatt_ = noattribs+1
   endtag_org = endtag
   do
      if ( nodata /= 0 ) then
         noattribs = 0
         tag = starttag
      elseif ( att_ < noatt_ .and. noatt_ > 1 ) then
         att_      = att_ + 1
         if ( att_ <= noatt_-1 ) then
            tag       = attribs(1,att_)
            data(1)   = attribs(2,att_)
            noattribs = 0
            nodata    = 1
            endtag    = .false.
         else
            tag       = starttag
            noattribs = 0
            nodata    = 0
            endtag    = .true.
            cycle
         endif
      else
         if ( endtag_org ) then
            return
         else
            call xml_get( info, tag, endtag, attribs, noattribs, data, nodata )
            if ( xml_error(info) ) then
               write(lurep_,*) 'Error reading input file!'
               error = .true.
               return
            endif
         endif
      endif
      if ( endtag .and. tag == starttag ) then
         exit
      endif
      if ( endtag .and. noattribs == 0 ) then
         if ( xml_ok(info) ) then
            cycle
         else
            exit
         endif
      endif
      select case( tag )
      case('id')
         call read_xml_integer( &
            info, tag, endtag, attribs, noattribs, data, nodata, &
            dvar%id, has_id )
      case('universe')
         call read_xml_integer( &
            info, tag, endtag, attribs, noattribs, data, nodata, &
            dvar%universe, has_universe )
      case('material')
         call read_xml_word( &
            info, tag, endtag, attribs, noattribs, data, nodata, &
            dvar%material, has_material )
      case('fill')
         call read_xml_integer( &
            info, tag, endtag, attribs, noattribs, data, nodata, &
            dvar%fill, has_fill )
      case('surfaces')
         call read_xml_integer_array( &
            info, tag, endtag, attribs, noattribs, data, nodata, &
            dvar%surfaces, has_surfaces )
      case('rotation')
         call read_xml_double_array( &
            info, tag, endtag, attribs, noattribs, data, nodata, &
            dvar%rotation, has_rotation )
      case('translation')
         call read_xml_double_array( &
            info, tag, endtag, attribs, noattribs, data, nodata, &
            dvar%translation, has_translation )
      case ('comment', '!--')
         ! Simply ignore
      case default
         if ( strict_ ) then
            error = .true.
            call xml_report_errors( info, &
               'Unknown or wrongly placed tag: ' // trim(tag))
         endif
      end select
      nodata = 0
      if ( .not. xml_ok(info) ) exit
   end do
   if ( .not. has_id ) then
      has_dvar = .false.
      call xml_report_errors(info, 'Missing data on id')
   endif
   if ( .not. has_surfaces ) then
      has_dvar = .false.
      call xml_report_errors(info, 'Missing data on surfaces')
   endif
   if ( .not. has_rotation ) then
      has_dvar = .false.
      call xml_report_errors(info, 'Missing data on rotation')
   endif
   if ( .not. has_translation ) then
      has_dvar = .false.
      call xml_report_errors(info, 'Missing data on translation')
   endif
end subroutine read_xml_type_cell_xml
subroutine init_xml_type_cell_xml_array( dvar )
   type(cell_xml), dimension(:), pointer :: dvar
   if ( associated( dvar ) ) then
      deallocate( dvar )
   endif
   allocate( dvar(0) )
end subroutine init_xml_type_cell_xml_array
subroutine init_xml_type_cell_xml(dvar)
   type(cell_xml) :: dvar
   dvar%universe = 0
   dvar%material = ''
   dvar%fill = 0
end subroutine init_xml_type_cell_xml
subroutine write_xml_type_cell_xml_array( &
      info, tag, indent, dvar )
   type(XML_PARSE)                                 :: info
   character(len=*), intent(in)                    :: tag
   integer                                         :: indent
   type(cell_xml), dimension(:)        :: dvar
   integer                                         :: i
   do i = 1,size(dvar)
       call write_xml_type_cell_xml( info, tag, indent, dvar(i) )
   enddo
end subroutine write_xml_type_cell_xml_array

subroutine write_xml_type_cell_xml( &
      info, tag, indent, dvar )
   type(XML_PARSE)                                 :: info
   character(len=*), intent(in)                    :: tag
   integer                                         :: indent
   type(cell_xml)                      :: dvar
   character(len=100)                              :: indentation
   indentation = ' '
   write(info%lun, '(4a)' ) indentation(1:min(indent,100)),&
       '<',trim(tag), '>'
   call write_to_xml_integer( info, 'id', indent+3, dvar%id)
   call write_to_xml_integer( info, 'universe', indent+3, dvar%universe)
   call write_to_xml_word( info, 'material', indent+3, dvar%material)
   call write_to_xml_integer( info, 'fill', indent+3, dvar%fill)
   call write_to_xml_integer_array( info, 'surfaces', indent+3, dvar%surfaces)
   call write_to_xml_double_array( info, 'rotation', indent+3, dvar%rotation)
   call write_to_xml_double_array( info, 'translation', indent+3, dvar%translation)
   write(info%lun,'(4a)') indentation(1:min(indent,100)), &
       '</' //trim(tag) // '>'
end subroutine write_xml_type_cell_xml

subroutine read_xml_type_surface_xml_array( &
      info, tag, endtag, attribs, noattribs, data, nodata, &
      dvar, has_dvar )
   type(XML_PARSE)                                 :: info
   character(len=*), intent(inout)                 :: tag
   logical, intent(inout)                          :: endtag
   character(len=*), dimension(:,:), intent(inout) :: attribs
   integer, intent(inout)                          :: noattribs
   character(len=*), dimension(:), intent(inout)   :: data
   integer, intent(inout)                          :: nodata
   type(surface_xml), dimension(:), pointer :: dvar
   logical, intent(inout)                       :: has_dvar

   integer                                      :: newsize
   type(surface_xml), dimension(:), pointer :: newvar

   jrt_surf_size = jrt_surf_size + 1
   
   !newsize = size(dvar) + 1
   !allocate( newvar(1:newsize) )
   !newvar(1:newsize-1) = dvar
   !deallocate( dvar )
   !dvar => newvar

   call read_xml_type_surface_xml( info, tag, endtag, attribs, noattribs, data, nodata, &
              dvar(jrt_surf_size), has_dvar )
end subroutine read_xml_type_surface_xml_array

subroutine read_xml_type_surface_xml( info, starttag, endtag, attribs, noattribs, data, nodata, &
              dvar, has_dvar )
   type(XML_PARSE)                                 :: info
   character(len=*), intent(in)                    :: starttag
   logical, intent(inout)                          :: endtag
   character(len=*), dimension(:,:), intent(inout) :: attribs
   integer, intent(inout)                          :: noattribs
   character(len=*), dimension(:), intent(inout)   :: data
   integer, intent(inout)                          :: nodata
   type(surface_xml), intent(inout)  :: dvar
   logical, intent(inout)                       :: has_dvar

   integer                                      :: att_
   integer                                      :: noatt_
   logical                                      :: error
   logical                                      :: endtag_org
   character(len=len(starttag))                 :: tag
   logical                                         :: has_id
   logical                                         :: has_type
   logical                                         :: has_coeffs
   logical                                         :: has_boundary
   has_id                               = .false.
   has_type                             = .false.
   has_coeffs                           = .false.
   has_boundary                         = .false.
   call init_xml_type_surface_xml(dvar)
   has_dvar = .true.
   error  = .false.
   att_   = 0
   noatt_ = noattribs+1
   endtag_org = endtag
   do
      if ( nodata /= 0 ) then
         noattribs = 0
         tag = starttag
      elseif ( att_ < noatt_ .and. noatt_ > 1 ) then
         att_      = att_ + 1
         if ( att_ <= noatt_-1 ) then
            tag       = attribs(1,att_)
            data(1)   = attribs(2,att_)
            noattribs = 0
            nodata    = 1
            endtag    = .false.
         else
            tag       = starttag
            noattribs = 0
            nodata    = 0
            endtag    = .true.
            cycle
         endif
      else
         if ( endtag_org ) then
            return
         else
            call xml_get( info, tag, endtag, attribs, noattribs, data, nodata )
            if ( xml_error(info) ) then
               write(lurep_,*) 'Error reading input file!'
               error = .true.
               return
            endif
         endif
      endif
      if ( endtag .and. tag == starttag ) then
         exit
      endif
      if ( endtag .and. noattribs == 0 ) then
         if ( xml_ok(info) ) then
            cycle
         else
            exit
         endif
      endif
      select case( tag )
      case('id')
         call read_xml_integer( &
            info, tag, endtag, attribs, noattribs, data, nodata, &
            dvar%id, has_id )
      case('type')
         call read_xml_word( &
            info, tag, endtag, attribs, noattribs, data, nodata, &
            dvar%type, has_type )
      case('coeffs')
         call read_xml_double_array( &
            info, tag, endtag, attribs, noattribs, data, nodata, &
            dvar%coeffs, has_coeffs )
      case('boundary')
         call read_xml_word( &
            info, tag, endtag, attribs, noattribs, data, nodata, &
            dvar%boundary, has_boundary )
      case ('comment', '!--')
         ! Simply ignore
      case default
         if ( strict_ ) then
            error = .true.
            call xml_report_errors( info, &
               'Unknown or wrongly placed tag: ' // trim(tag))
         endif
      end select
      nodata = 0
      if ( .not. xml_ok(info) ) exit
   end do
   if ( .not. has_id ) then
      has_dvar = .false.
      call xml_report_errors(info, 'Missing data on id')
   endif
   if ( .not. has_type ) then
      has_dvar = .false.
      call xml_report_errors(info, 'Missing data on type')
   endif
   if ( .not. has_coeffs ) then
      has_dvar = .false.
      call xml_report_errors(info, 'Missing data on coeffs')
   endif
end subroutine read_xml_type_surface_xml
subroutine init_xml_type_surface_xml_array( dvar )
   type(surface_xml), dimension(:), pointer :: dvar
   if ( associated( dvar ) ) then
      deallocate( dvar )
   endif
   allocate( dvar(0) )
end subroutine init_xml_type_surface_xml_array
subroutine init_xml_type_surface_xml(dvar)
   type(surface_xml) :: dvar
   dvar%boundary = 'transmit'
end subroutine init_xml_type_surface_xml
subroutine write_xml_type_surface_xml_array( &
      info, tag, indent, dvar )
   type(XML_PARSE)                                 :: info
   character(len=*), intent(in)                    :: tag
   integer                                         :: indent
   type(surface_xml), dimension(:)        :: dvar
   integer                                         :: i
   do i = 1,size(dvar)
       call write_xml_type_surface_xml( info, tag, indent, dvar(i) )
   enddo
end subroutine write_xml_type_surface_xml_array

subroutine write_xml_type_surface_xml( &
      info, tag, indent, dvar )
   type(XML_PARSE)                                 :: info
   character(len=*), intent(in)                    :: tag
   integer                                         :: indent
   type(surface_xml)                      :: dvar
   character(len=100)                              :: indentation
   indentation = ' '
   write(info%lun, '(4a)' ) indentation(1:min(indent,100)),&
       '<',trim(tag), '>'
   call write_to_xml_integer( info, 'id', indent+3, dvar%id)
   call write_to_xml_word( info, 'type', indent+3, dvar%type)
   call write_to_xml_double_array( info, 'coeffs', indent+3, dvar%coeffs)
   call write_to_xml_word( info, 'boundary', indent+3, dvar%boundary)
   write(info%lun,'(4a)') indentation(1:min(indent,100)), &
       '</' //trim(tag) // '>'
end subroutine write_xml_type_surface_xml

subroutine read_xml_type_lattice_xml_array( &
      info, tag, endtag, attribs, noattribs, data, nodata, &
      dvar, has_dvar )
   type(XML_PARSE)                                 :: info
   character(len=*), intent(inout)                 :: tag
   logical, intent(inout)                          :: endtag
   character(len=*), dimension(:,:), intent(inout) :: attribs
   integer, intent(inout)                          :: noattribs
   character(len=*), dimension(:), intent(inout)   :: data
   integer, intent(inout)                          :: nodata
   type(lattice_xml), dimension(:), pointer :: dvar
   logical, intent(inout)                       :: has_dvar

   integer                                      :: newsize
   type(lattice_xml), dimension(:), pointer :: newvar

   newsize = size(dvar) + 1
   allocate( newvar(1:newsize) )
   newvar(1:newsize-1) = dvar
   deallocate( dvar )
   dvar => newvar

   call read_xml_type_lattice_xml( info, tag, endtag, attribs, noattribs, data, nodata, &
              dvar(newsize), has_dvar )
end subroutine read_xml_type_lattice_xml_array

subroutine read_xml_type_lattice_xml( info, starttag, endtag, attribs, noattribs, data, nodata, &
              dvar, has_dvar )
   type(XML_PARSE)                                 :: info
   character(len=*), intent(in)                    :: starttag
   logical, intent(inout)                          :: endtag
   character(len=*), dimension(:,:), intent(inout) :: attribs
   integer, intent(inout)                          :: noattribs
   character(len=*), dimension(:), intent(inout)   :: data
   integer, intent(inout)                          :: nodata
   type(lattice_xml), intent(inout)  :: dvar
   logical, intent(inout)                       :: has_dvar

   integer                                      :: att_
   integer                                      :: noatt_
   logical                                      :: error
   logical                                      :: endtag_org
   character(len=len(starttag))                 :: tag
   logical                                         :: has_id
   logical                                         :: has_type
   logical                                         :: has_dimension
   logical                                         :: has_lower_left
   logical                                         :: has_width
   logical                                         :: has_universes
   has_id                               = .false.
   has_type                             = .false.
   has_dimension                        = .false.
   has_lower_left                       = .false.
   has_width                            = .false.
   has_universes                        = .false.
   call init_xml_type_lattice_xml(dvar)
   has_dvar = .true.
   error  = .false.
   att_   = 0
   noatt_ = noattribs+1
   endtag_org = endtag
   do
      if ( nodata /= 0 ) then
         noattribs = 0
         tag = starttag
      elseif ( att_ < noatt_ .and. noatt_ > 1 ) then
         att_      = att_ + 1
         if ( att_ <= noatt_-1 ) then
            tag       = attribs(1,att_)
            data(1)   = attribs(2,att_)
            noattribs = 0
            nodata    = 1
            endtag    = .false.
         else
            tag       = starttag
            noattribs = 0
            nodata    = 0
            endtag    = .true.
            cycle
         endif
      else
         if ( endtag_org ) then
            return
         else
            call xml_get( info, tag, endtag, attribs, noattribs, data, nodata )
            if ( xml_error(info) ) then
               write(lurep_,*) 'Error reading input file!'
               error = .true.
               return
            endif
         endif
      endif
      if ( endtag .and. tag == starttag ) then
         exit
      endif
      if ( endtag .and. noattribs == 0 ) then
         if ( xml_ok(info) ) then
            cycle
         else
            exit
         endif
      endif
      select case( tag )
      case('id')
         call read_xml_integer( &
            info, tag, endtag, attribs, noattribs, data, nodata, &
            dvar%id, has_id )
      case('type')
         call read_xml_word( &
            info, tag, endtag, attribs, noattribs, data, nodata, &
            dvar%type, has_type )
      case('dimension')
         call read_xml_integer_array( &
            info, tag, endtag, attribs, noattribs, data, nodata, &
            dvar%dimension, has_dimension )
      case('lower_left')
         call read_xml_double_array( &
            info, tag, endtag, attribs, noattribs, data, nodata, &
            dvar%lower_left, has_lower_left )
      case('width')
         call read_xml_double_array( &
            info, tag, endtag, attribs, noattribs, data, nodata, &
            dvar%width, has_width )
      case('universes')
         call read_xml_integer_array( &
            info, tag, endtag, attribs, noattribs, data, nodata, &
            dvar%universes, has_universes )
      case ('comment', '!--')
         ! Simply ignore
      case default
         if ( strict_ ) then
            error = .true.
            call xml_report_errors( info, &
               'Unknown or wrongly placed tag: ' // trim(tag))
         endif
      end select
      nodata = 0
      if ( .not. xml_ok(info) ) exit
   end do
   if ( .not. has_id ) then
      has_dvar = .false.
      call xml_report_errors(info, 'Missing data on id')
   endif
   if ( .not. has_dimension ) then
      has_dvar = .false.
      call xml_report_errors(info, 'Missing data on dimension')
   endif
   if ( .not. has_lower_left ) then
      has_dvar = .false.
      call xml_report_errors(info, 'Missing data on lower_left')
   endif
   if ( .not. has_width ) then
      has_dvar = .false.
      call xml_report_errors(info, 'Missing data on width')
   endif
   if ( .not. has_universes ) then
      has_dvar = .false.
      call xml_report_errors(info, 'Missing data on universes')
   endif
end subroutine read_xml_type_lattice_xml
subroutine init_xml_type_lattice_xml_array( dvar )
   type(lattice_xml), dimension(:), pointer :: dvar
   if ( associated( dvar ) ) then
      deallocate( dvar )
   endif
   allocate( dvar(0) )
end subroutine init_xml_type_lattice_xml_array
subroutine init_xml_type_lattice_xml(dvar)
   type(lattice_xml) :: dvar
   dvar%type = 'rectangular'
end subroutine init_xml_type_lattice_xml
subroutine write_xml_type_lattice_xml_array( &
      info, tag, indent, dvar )
   type(XML_PARSE)                                 :: info
   character(len=*), intent(in)                    :: tag
   integer                                         :: indent
   type(lattice_xml), dimension(:)        :: dvar
   integer                                         :: i
   do i = 1,size(dvar)
       call write_xml_type_lattice_xml( info, tag, indent, dvar(i) )
   enddo
end subroutine write_xml_type_lattice_xml_array

subroutine write_xml_type_lattice_xml( &
      info, tag, indent, dvar )
   type(XML_PARSE)                                 :: info
   character(len=*), intent(in)                    :: tag
   integer                                         :: indent
   type(lattice_xml)                      :: dvar
   character(len=100)                              :: indentation
   indentation = ' '
   write(info%lun, '(4a)' ) indentation(1:min(indent,100)),&
       '<',trim(tag), '>'
   call write_to_xml_integer( info, 'id', indent+3, dvar%id)
   call write_to_xml_word( info, 'type', indent+3, dvar%type)
   call write_to_xml_integer_array( info, 'dimension', indent+3, dvar%dimension)
   call write_to_xml_double_array( info, 'lower_left', indent+3, dvar%lower_left)
   call write_to_xml_double_array( info, 'width', indent+3, dvar%width)
   call write_to_xml_integer_array( info, 'universes', indent+3, dvar%universes)
   write(info%lun,'(4a)') indentation(1:min(indent,100)), &
       '</' //trim(tag) // '>'
end subroutine write_xml_type_lattice_xml

subroutine read_xml_file_geometry_t(fname, lurep, errout)
   character(len=*), intent(in)           :: fname
   integer, intent(in), optional          :: lurep
   logical, intent(out), optional         :: errout
   integer :: surf_ctr
   integer :: cell_ctr

   type(XML_PARSE)                        :: info
   logical                                :: error
   character(len=80)                      :: tag
   character(len=80)                      :: starttag
   logical                                :: endtag
   character(len=250), dimension(1:2,1:20) :: attribs
   integer                                :: noattribs
   character(len=1000), dimension(1:1000)  :: data
   integer                                :: nodata
   logical                                         :: has_cell_
   logical                                         :: has_surface_
   logical                                         :: has_lattice_
   has_cell_                            = .false.
   ! upped this to be huge
   allocate(cell_(NCELLS))
   has_surface_                         = .false.
   allocate(surface_(NSURFACES))
   has_lattice_                         = .false.
   allocate(lattice_(0))

   surf_ctr = 0
   cell_ctr = 0

   call init_xml_file_geometry_t
   call xml_open( info, fname, .true. )
   call xml_options( info, report_errors=.false., ignore_whitespace=.true.)
   lurep_ = 0
   if ( present(lurep) ) then
      lurep_ = lurep
      call xml_options( info, report_lun=lurep )
   endif
   do
      call xml_get( info, starttag, endtag, attribs, noattribs, &
         data, nodata)
      if ( starttag /= '!--' ) exit
   enddo
   if ( starttag /= "geometry" ) then
      call xml_report_errors( info, &
         'XML-file should have root element "geometry"')
      error = .true.
      call xml_close(info)
      return
   endif
   strict_ = .false.
   error = .false.
   
   jrt_cell_size = 0
   jrt_surf_size = 0
   ! this is our troubled loop
   do

		!if( surf_ctr + cell_ctr == 50000 ) then
			!call EXIT(0)
		!endif


      call xml_get( info, tag, endtag, attribs, noattribs, data, nodata )
      if ( xml_error(info) ) then
         write(lurep_,*) 'Error reading input file!'
         error = .true.
         return
      endif
      if ( endtag .and. tag == starttag ) then
         exit
      endif
      if ( endtag .and. noattribs == 0 ) then
         if ( xml_ok(info) ) then
            cycle
         else
            exit
         endif
      endif
      select case( tag )
      case('cell')
	  	 cell_ctr = cell_ctr + 1
         call read_xml_type_cell_xml_array( &
            info, tag, endtag, attribs, noattribs, data, nodata, &
            cell_, has_cell_ )
      case('surface')
	     surf_ctr = surf_ctr + 1
         call read_xml_type_surface_xml_array( &
            info, tag, endtag, attribs, noattribs, data, nodata, &
            surface_, has_surface_ )
      case('lattice')
         call read_xml_type_lattice_xml_array( &
            info, tag, endtag, attribs, noattribs, data, nodata, &
            lattice_, has_lattice_ )
      case ('comment', '!--')
         ! Simply ignore
      case default
         if ( strict_ ) then
            error = .true.
            call xml_report_errors( info, &
               'Unknown or wrongly placed tag: ' // trim(tag))
         endif
      end select
      nodata = 0
      if ( .not. xml_ok(info) ) exit
   end do
   if ( .not. has_cell_ ) then
      error = .true.
      call xml_report_errors(info, 'Missing data on cell_')
   endif
   if ( .not. has_surface_ ) then
      error = .true.
      call xml_report_errors(info, 'Missing data on surface_')
   endif
   if ( .not. has_lattice_ ) then
      error = .true.
      call xml_report_errors(info, 'Missing data on lattice_')
   endif
   if ( present(errout) ) errout = error
   call xml_close(info)
end subroutine

subroutine write_xml_file_geometry_t(fname, lurep)
   character(len=*), intent(in)           :: fname
   integer, intent(in), optional          :: lurep

   type(XML_PARSE)                        :: info
   integer                                :: indent = 0

   call xml_open( info, fname, .false. )
   call xml_options( info, report_errors=.true.)
   if ( present(lurep) ) then
       call xml_options( info, report_errors=.true.)
   endif
   write(info%lun,'(a)') &
      '<geometry>'
   call write_xml_type_cell_xml_array( info, 'cell', indent+3, cell_)
   call write_xml_type_surface_xml_array( info, 'surface', indent+3, surface_)
   call write_xml_type_lattice_xml_array( info, 'lattice', indent+3, lattice_)
   write(info%lun,'(a)') '</geometry>'
   call xml_close(info)
end subroutine

subroutine init_xml_file_geometry_t

end subroutine

end module
