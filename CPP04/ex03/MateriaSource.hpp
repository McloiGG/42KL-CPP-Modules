#pragma once
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria*	materias[4];

		void	clearMaterias();
		void	copyMaterias(MateriaSource const & other);

	public:
		MateriaSource();
		MateriaSource(MateriaSource const & other);
		MateriaSource&	operator=(MateriaSource const & other);
		virtual ~MateriaSource();

		virtual void		learnMateria(AMateria* m);
		virtual AMateria*	createMateria(std::string const & type);
};

#endif
